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

---

## 📋 Getting Started

### 1. Integration Methods
To utilize the **Character Locomotion System**, you can choose between two primary integration paths:

- **Create a Child Class**: Native inheritance allows for clean extension of all CLS features. Right-click in the Content Browser > Blueprint Class > Search and select `NewCharacter`.
- **Change Parent Class**: For existing projects, open your character blueprint, go to **Class Settings**, and update the **Parent Class** to `NewCharacter`.

### 2. Feature Exploration
A dedicated overview blueprint is included to showcase all available functions and logic hooks:
`All > Plugins > CharacterLocomotionSystem Content > Overview > Blueprint > BP_NC_Overview`

---

## 🛠️ Configuration & Data Assets

CLS uses **Advanced Primary Data Assets** for high-fidelity control over movement states like Vault, Mantle, and Climb Up.

### Editable Properties:
| Property | Description |
| :--- | :--- |
| **Warp Target Offsets** | Precisely adjust landing/transition points relative to character root. |
| **Warp Target Names** | Identifier strings for synchronized animation warping. |
| **Movement Montage** | The core animation sequence used for the movement state. |
| **Timing Controls** | Granular control over **Start Duration**, **Play Rate**, and **Blend Out Time**. |

---

## 🔍 Debugging & Level Design

The plugin includes a robust set of debugging utilities to accelerate development:
- **Real-time State Monitoring**: Toggle visual debuggers to track movement states and collision detection.
- **Level Design Validation**: Streamline the placement of climbable and vaultable surfaces with instant visual feedback.

---

## 🔗 Resources

> [!TIP]
> The sample project provides a "Gold Standard" implementation that serves as an excellent reference for production-grade setups.

- 📥 **[Sample Project Showcase](https://drive.google.com/drive/folders/1DdGjiWPIfIX7JbedweNz_dY-VXvpT5hz?usp=sharing)**

---

## 🏳️ License & Disclaimer

Released under the **MIT License**.  
*Note: This system is in active development. While engineered for stability, extensive testing is recommended for production environments.*

© 2024 Shankharaj Datta


