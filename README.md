# Character Locomotion System (CLS)

[![Unreal Engine](https://img.shields.io/badge/Unreal%20Engine-5.3%20%7C%205.4%20%7C%205.5-blue?logo=unrealengine&logoColor=white)](https://www.unrealengine.com/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Development Stage](https://img.shields.io/badge/Stage-Active%20Development-orange)](README.md)
[![Multiplayer](https://img.shields.io/badge/Network-Fully%20Replicated-brightgreen)](README.md)

**Character Locomotion System (CLS)** is a high-performance, C++ based movement framework for Unreal Engine 5. Designed for AAA-grade fidelity and technical flexibility, CLS provides a robust foundation for advanced character traversal, featuring a data-driven architecture and native Motion Warping integration.

---

## 🚀 Core Technical Pillars

| Pillar | Description |
| :--- | :--- |
| **Data-Driven Workflow** | Utilize `PrimaryDataAsset` to configure Vault, Mantle, and Climb parameters without touching code. |
| **Motion Warping** | Native integration with Epic's Motion Warping plugin for pixel-perfect environmental interactions. |
| **C++ Performance** | Highly optimized `UNewCharacterMovementComponent` designed for low-latency and high scalability. |
| **Multiplayer Ready** | Engineered with full predictive replication for synchronized gameplay in competitive environments. |

---

## 🕹️ Advanced Movement Modes

The system extends the standard Unreal movement component to support a wide array of high-fidelity traversal states:

- **🛡️ Prone & Slide**: Seamless transitions between standing, crouching, and prone. Dynamic sliding with custom eye-height adjustments.
- **🧗 Advanced Climbing**: Comprehensive system for vertical navigation, including specialized **Climb Up** logic.
- **🏃 Wall Run**: Dynamic surface detection for fluid horizontal and vertical wall traversal.
- **⚡ Dash**: High-speed, directionally-aware bursts for combat and evasive maneuvers.
- **🤸 Parkour (Vault & Mantle)**: Context-aware movement that smoothly blends animations using motion warping for realistic obstacle traversal.

---

## 🛠️ Technical Implementation

### Motion Warping Integration
CLS leverages `UMotionWarpingComponent` to ensure that parkour moves like vaulting and mantling land exactly where they should. Warp targets are dynamically updated based on the environment geometry.

### Data Assets
Movement configurations are decoupled from the character logic. By using `UVaultPrimaryDataAsset`, `UMantlePrimaryDataAsset`, and others, designers can:
- Swap montages instantly.
- Adjust playback rates and blend times.
- Fine-tune warp target offsets per-move.

### Smooth Camera Dynamics
Built-in support for dynamic eye-height adjustments ensuring a nauseous-free experience during high-speed transitions like sliding or vaulting.

---

## 📋 Integration & Usage

### Supported Versions
- **Unreal Engine 5.3**
- **Unreal Engine 5.4**
- **Unreal Engine 5.5**

### Quick Start
1. **Enable Plugins**: Ensure **Motion Warping** is enabled in your project.
2. **Inherit**: Create a new Character Blueprint inheriting from `ANewCharacter`.
3. **Configure**: Assign your custom Movement Data Assets to the character.
4. **Input**: Bind the provided functions (e.g., `CrouchSprint`, `Vault`, `Prone`) to your Enhanced Input actions.

---

## 🔗 Resources

> [!TIP]
> Get started quickly by exploring the official sample project and deep-diving into the technical documentation.

- 📥 **[Sample Project Showcase](https://drive.google.com/drive/folders/1DdGjiWPIfIX7JbedweNz_dY-VXvpT5hz?usp=sharing)**
- 📖 **[Technical Documentation (PDF)](https://docs.google.com/document/d/1ZGNJ7G3xG42ZnxNOpL2sVa1HN4Bb6B7Bkgt0RbDWhMM/edit?usp=sharing)**

---

## 🏳️ License & Disclaimer

Released under the **MIT License**.  
*Note: This system is in active development. While engineered for stability, extensive testing is recommended for production environments.*

© 2024 Shankharaj Datta

