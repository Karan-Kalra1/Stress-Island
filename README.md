# Stress Island Demo

A first-person open-world survival prototype developed in **Unreal Engine** with the goal of learning the engine. The project was built to explore and implement core survival mechanics—including inventory management, crafting, resource harvesting, dynamic stat degradation, and scalable item effects—using a lightweight C++ foundation combined with Blueprint systems.

---

## 🎮 Gameplay Features

* **Survival Vitals:** Interdependent Health, Stamina, Hunger, and Thirst systems.
  * Sprinting consumes **Stamina**.
  * **Thirst** and **Hunger** deplete over time.
  * Depleted Thirst accelerates Hunger loss; depleted Hunger drains **Health**.
* **Resource Harvesting & Tool Efficiency:**
  * Collect raw resources like **Twigs** and **Stones** from the ground.
  * Chop down trees barehanded or use a crafted **Axe** for significantly higher efficiency.
* **Inventory & Crafting Systems:**
  * **Inventory Management:** Store, inspect, use, or drop items directly from the UI.
  * **Dynamic Building/Crafting Tab:** Displays available recipes based on current inventory contents.
  * **Recipe Cooking:** Light a **Campfire** to cook raw meat dropped by enemies to yield higher hunger replenishment.
* **Combat & AI:** Aggressive enemies spawn across the island, pursuit-pathing to attack on sight. Defeating enemies rewards raw meat resources.
* **In-Game Guide:** Dynamic help overlay (`H`) explaining controls and core gameplay loop.

---

## 🛠️ Controls & Keybindings

| Key | Action |
| :--- | :--- |
| **W / A / S / D** | Movement |
| **Left Shift** | Sprint *(Consumes Stamina)* |
| **E** | Pick up ground items (Twigs, Stones, Meat) / Interact |
| **Q** | Toggle Inventory & Building/Crafting Menu |
| **T** | Drink Water *(Must be near dynamic water bodies)* |
| **Left Click** | Use UI |
| **Right Click** | Attack/Chop Trees |
| **H** | Open In-Game Help & Systems Guide |

---

## 🏗️ Architecture & Technical Highlights

The project emphasizes **modularity, scalability, and loose coupling** to make adding new items, recipes, and effects straightforward:

* **Hybrid C++ / Blueprint Core:**
  * **Health Component** is handled in native **C++** to test out C++ side of the engine.
  * Most of the game logic, interactions, and UI components are structured via **Unreal Blueprints**.
* **Data-Driven Building & Crafting:**
  * Powered by **Data Assets** (`BuildingData`) and Data Tables (`item_Data`) to seamlessly register new crafting recipes without modifying UI logic.
* **Modular Item & Effect System:**
  * Utilizes extensible `ItemEffect` classes (`Food_Raw`, `Food_Cooked`) to define consumed item actions modularly.
  
* **Data-Driven Inventory System:**
  * **`FItemStruct` & `FSlotStruct`**: Define structured item data and inventory slot configurations.
  * **`item_Data` (Data Table)**: Centralizes item definitions to seamlessly introduce new items.
  * **`itemDataComponent` & `InventorySystem`**: Modular actor components managing player storage and item state updates.

* **Decoupling via Interfaces:**
  * Built using Blueprint Interfaces (`IInteractInterface`) to allow clean interaction between the player character, harvestable actors, dropped items, and building structures.

---

## 📁 Project Directory Structure

```text
Content/
├── BuildingSystem/
│   ├── BuildingData/       # Data Assets for Crafting Recipes (Axe, FirePit)
│   ├── BuildingPiece/      # Building Actor Blueprints (Campfire, BuildingPieceBase)
│   └── UI/                 # UI Icons for Building
├── Characters/             # Animations,Materials,Rigs
├── FirstPerson/            # FirstPerson Player & Enemy Character Logic
├── Input/                  # Input Contexts & Actions
├── Inventory/
│   ├── Items/              # World Item Blueprints (Log, Stone, Twig, Raw/Cooked Meat)
│   │   ├── Effect/         # Item Effect Blueprints (Food_Raw, Food_Cooked)
│   │   └── Icons/          # UI Item Icons
│   ├── UI/                 # Inventory & Crafting UI Widgets
│   ├── FItemStruct         # Item Definition Struct
│   ├── FSlotStruct         # Inventory Slot Struct
│   ├── IInteractInterface  # Blueprint Interaction Interface
│   ├── InventorySystem     # Inventory Component Blueprint
│   ├── item_Data           # Item Data Table
│   └── itemDataComponent   # Item Data Component
├── LevelPrototyping/       # Generated Starter Project files
├── Nodes/                  # Base Node Class, and Tree Node
├── StarterContent/         # Default Unreal Assets
├── Tools/                  # Tool Actors (Axe)
└── UI/                     # Global UI & Main HUD Widgets

C++ Classes/
└── StressIsland/
    └── StatComponent     # C++ Component handling entity health logic