# PingPong

A Pong clone built with C++ and SFML 3.0.2.

## Build & Run

```bash
cmake -B build
cmake --build build
./build/PingPong
```

Windows builds are available as `release-win32.zip` and `release-win64.zip` on the [Releases](../../releases) page.

---

## Requirements

### 1. C++ (not C)

The project uses modern C++ features throughout:

| Feature | Location |
|---|---|
| `std::variant` for polymorphic drawable types | `include/Game/Core/Actor/Actor.hpp` |
| `std::visit` with lambdas for type-safe operations | `src/Game/Core/Actor/Actor.cpp` |
| `std::function` for callbacks and scene factory | `include/Game/Core/Actor/Actor.hpp` |
| `if constexpr` for compile-time type exclusion | `src/Game/Core/Actor/Actor.cpp` |
| `std::optional` for SFML 3 event polling | `src/Core/GameInstance/GameInstance.cpp` |
| Templates for singleton base and factory method | `include/Core/Instance/Instance.hpp` |

---

### 2. OOP

**Inheritance hierarchy:** `Actor` -> `Pawn` -> `Player` / `AIPlayer`

`update(float deltaTime)` is virtual and overridden at each level of the hierarchy. Each class extends the behavior of its parent without replacing it entirely.

| Class | File |
|---|---|
| `Actor::update` | `src/Game/Core/Actor/Actor.cpp` |
| `Pawn::update` | `src/Game/Core/Pawn/Pawn.cpp` |
| `Player::update` | `src/Game/Player/Player.cpp` |
| `AIPlayer::update` | `src/Game/Player/AIPlayer.cpp` |

The **passkey idiom** (`Actor::Private`) enforces `shared_ptr`-only construction while keeping the constructor public and compatible with `std::make_shared`. `enable_shared_from_this` allows safe `shared_ptr` self-reference from within member functions.

`applyShape` and `applyVelocity` are split from their chaining counterparts (`setShape`, `setVelocity`) specifically to allow safe calls from constructors, before `shared_from_this()` becomes available.

---

### 3. STL

| Container / Smart Pointer | Usage | Location |
|---|---|---|
| `std::vector<std::shared_ptr<Actor>>` | Scene actor storage | `include/Core/Scene/Scene.hpp` |
| `std::unique_ptr<MovementComponent>` | Exclusive movement ownership in `Pawn` | `include/Game/Core/Pawn/Pawn.hpp` |
| `std::map<EventKey, std::function<...>>` | Event binding registry | `include/Core/Controller/Controller.hpp` |
| `std::weak_ptr<T>` | Non-owning actor references in callbacks | `include/Core/Controller/Controller.hpp` |
| `std::shared_ptr<Actor>` | All actor lifetime management | Throughout |

---

### 4. Code formatting and structure

`.clang-format` is present at the project root and applied to all source files.

The project is split into two independent layers:

- `include/Core` and `src/Core` contain the engine: game loop, rendering, input, collision, scene management.
- `include/Game` and `src/Game` contain game-specific logic: actors, players, ball, movement.

This separation means the core engine has no knowledge of game-specific types.

---

### 6. External libraries

SFML 3.0.2 is used for rendering, windowing, input, and events. It is declared as a CMake dependency in `ext/CMakeLists.txt` and fetched automatically at build time with no manual installation required.

---

### 7. Game engine architecture

The game loop runs in `GameInstance::runGame` with delta time capped at 50ms to prevent physics spikes on lag frames. Each frame is divided into three explicit phases:

1. **Input** collected and dispatched by `Controller` (`src/Core/Controller/Controller.cpp`)
2. **Update** called on every actor in the scene (`src/Core/GameInstance/GameInstance.cpp`)
3. **Render** performed by `Renderer` using a virtual resolution view (`src/Core/Renderer/Renderer.cpp`)

Collision detection runs as a separate pass between update and render in `CollisionManager` (`src/Core/Collision/CollisionManager.cpp`).

`Scene` is a pure data container with no logic of its own (`include/Core/Scene/Scene.hpp`).

`Renderer` applies a `sf::View` with letterbox scaling so all game coordinates are authored against a fixed 1440x790 virtual resolution and scale correctly to any screen size.

---

### 8. Design patterns

**Singleton**

`Instance<T>` is a CRTP base class that provides a `getInstance()` static method. Used by `Renderer`, `Controller`, `CollisionManager`, and `GameInstance`. The instance is created on first call and destroyed on program exit.

```
include/Core/Instance/Instance.hpp
```

**Factory Method**

`Actor::create<T>()` is a static template factory that constructs any `Actor` subclass through `std::make_shared`. The passkey idiom ensures this is the only way to create actors.

```
include/Game/Core/Actor/Actor.hpp
```

**Component**

`MovementComponent` encapsulates input accumulation (`addMovementInput`) and velocity application (`consumeInput`). It is owned exclusively by `Pawn` via `std::unique_ptr` and called each frame during `Pawn::update`.

```
include/Game/Core/Movement/Components/MovementComponents.hpp
src/Game/Core/Movement/Components/MovementComponent.cpp
```

**Observer**

`Controller::bindEvent` registers typed input callbacks against a `std::weak_ptr` to the target actor. If the actor is destroyed, the callback is silently skipped. Used by `Player` to bind keyboard keys to movement methods.

```
include/Core/Controller/Controller.hpp
src/Game/Player/Player.cpp
```

**Builder / Method chaining**

All `Actor` setters return `std::shared_ptr` to `self`, allowing fluent multi-step construction in a single expression. Derived classes such as `AIPlayer` return their own type (`std::shared_ptr<AIPlayer>`) to preserve the concrete type through the chain.

```
src/Game/Core/Actor/Actor.cpp
main.cpp
```

---

### 9. Compilation and portability

The project compiles and runs on Win32, Win64, and macOS. GitHub Actions builds both Windows targets on every release via `.github/workflows/build.yml` and uploads the resulting archives through `.github/workflows/cd.yml`. SFML is fetched automatically by CMake so no additional setup is needed on a fresh machine.
