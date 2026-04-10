# Pixel-Art

A CoreXY bead-placement machine for creating physical monochrome pixel art on perforated acrylic sheets.

## 3D Model Preview

[View 3D Model on Sketchfab](https://sketchfab.com/3d-models/pixel-art-first-draft-e8df2f01db034dc6a11d05934eb7d457)

## Overview

Pixel-Art is an open-source CNC machine that automatically places beads into a grid of holes on an acrylic sheet, producing physical pixel art from digital images. The machine uses a CoreXY motion system for fast, precise XY movement and a bead dropper mechanism as the end effector.

## Specifications

| Parameter | Value |
|-----------|-------|
| Build Area | 400 × 400 mm |
| Resolution | 2–10 mm per pixel (configurable) |
| Color Mode | Monochrome (black, white, grey beads) |
| Motion System | CoreXY |
| Controller | ESP32 + GRBL |
| Frame | 2020 aluminum extrusion |
| Motors | NEMA17 steppers |
| Belt | GT2 timing belt |

## Roles 

MACHINE GANTERY -- NADEC
END EFFECTOR --- KEVIN
ELECTRONICS -- MERIN
FIRMWARE ---  ARCHITHA
INTERFACE --- KURIAN
DOCUMENTION --- MERIN
FABRICATION AND INTERGRATION --- KURIAN
PRESENTAION & VIDEO (1 MIN) --- ARCHITHA

## TIMELINE

APRIL 09 --  INITAL DISCUSSION AND TEAM ALLOCATION
APRIL 10 --  SKETCH THE DESIGN, MACHINE GANTERY DESIGN AND INTERFACE DESIGN (GET THE GCOD FOR MACHINE)
APRIL 11 --  DESIGN AND FIX THE END EFFECTOR WORKING STRUCTER 
APRIL 12 --  END EFFECTOR DESIGN ( GET THE PROPER MEASURMENT FOR THE BEADS AND BASED ON THAT WE NEEDED TO WORK, **DO IT PARAMETRIC** ), ELECTROCNIC DESIGN 
APRIL 13 --  CHECK THE GCODES WORKING GANTERY MOVEMENT, FIRMWARE 
APRIL 14 --
APRIL 15 -- FABRICATION AND INTERGRATION
APRIL 16 -- 
APRIL 17 --
APRIL 18 --
APRIL 19 --
APRIL (20 - 21) -- VIDEO EDITIONG &  PRESENTAION



## How It Works

1. **Image Input** — A monochrome image is converted to G-code with pixel coordinates mapped to hole positions
2. **Bead Loading** — Beads are loaded into the dropper mechanism (sorted by color)
3. **Placement** — The CoreXY gantry moves to each hole position and the dropper releases a bead
4. **Result** — Completed pixel art on the acrylic sheet

## Bill of Materials

### Frame & Motion

- 2020 V-slot aluminum extrusion
- GT2 timing belt + pulleys (16T/20T)
- NEMA17 stepper motors (×2 for XY)
- Linear rails / V-slot wheels
- 625 bearings for idlers

### Electronics

- ESP32 development board
- DRV8825 / TMC2209 stepper drivers
- 12V/24V power supply
- Limit switches (×3)

### End Effector

- Bead dropper mechanism (servo/solenoid actuated)
- Bead hopper/feeder

### Substrate

- Perforated acrylic sheet (hole spacing matches resolution)
- Beads (2–10 mm diameter, black/white/grey)

## Repository Structure

```
Pixel-Art/
├── Core-XY Movement - Nadec/
│   ├── Solidworks Files/      # Editable CAD files
│   ├── STL AND STEP FILES/    # Export files for fabrication
│   └── initial files/         # Reference designs
├── Documentation/
│   └── Documentation.md
└── README.md
```

## Build Status

- [x] CoreXY gantry design (first draft)
- [ ] End effector dropper mechanism
- [ ] Electronics integration
- [ ] Firmware (ESP32-GRBL)
- [ ] Image-to-Gcode converter
- [ ] Assembly documentation

---

## Git Workflow

### First Time Setup (Clone the Repo)

```bash
git clone https://github.com/NB6RULES/Pixel-Art.git
cd Pixel-Art
git lfs install
git lfs pull
```

> **Note:** This repo uses Git LFS for large STL/STEP files. Run `git lfs install` once on your machine.

### Daily Workflow

#### 1. Always Pull Before You Start Working

```bash
git pull
```

This syncs your local copy with the latest changes from GitHub.

#### 2. Check What's Changed

```bash
git status
```

Shows modified, staged, and untracked files.

#### 3. Stage Your Changes

```bash
# Add specific file
git add filename.SLDPRT

# Add all changes
git add .
```

#### 4. Commit Your Changes

```bash
git commit -m "Brief description of what you changed"
```

Write clear commit messages — future you will thank present you.

#### 5. Pull Again Before Pushing

```bash
git pull
```

**Always pull before push** to avoid merge conflicts, especially when collaborating.

#### 6. Push to GitHub

```bash
git push
```

### Quick Reference

| Command | What it does |
|---------|--------------|
| `git clone <url>` | Download repo for the first time |
| `git pull` | Get latest changes from GitHub |
| `git status` | See what files changed |
| `git add .` | Stage all changes |
| `git commit -m "msg"` | Save changes locally with a message |
| `git push` | Upload commits to GitHub |
| `git log --oneline` | View commit history |

### Golden Rule

```
PULL → WORK → ADD → COMMIT → PULL → PUSH
```

---

## Getting Started

### Prerequisites

- SolidWorks (or use STEP files for other CAD software)
- 3D printer for custom brackets
- Basic CNC/electronics assembly experience

### Assembly

*Documentation in progress*

## Dependencies & Key Libraries

### [GRBL](https://github.com/grbl/grbl)
The original open-source, high-performance G-code motion controller written in optimized C. GRBL is the foundation of the motion control strategy used in this project — it handles real-time step generation, acceleration planning, and G-code parsing. We reference it as the upstream standard that our ESP32 port is based on.

### [Grbl_ESP32 (bdring)](https://github.com/bdring/grbl_esp32)
A port of GRBL adapted specifically for the ESP32 microcontroller. We chose this because the ESP32 offers Wi-Fi connectivity, more GPIO pins, and faster processing than the original Arduino Uno target. This firmware runs directly on our controller board and interprets G-code sent from the image processing pipeline.

### [NeoPI_Wireless (saheenpalayi)](https://github.com/saheenpalayi/NeoPI_Wireless)
A wireless interface layer for sending G-code over Wi-Fi to an ESP32-based CNC controller. We use this (or draw from its approach) to enable cable-free communication between the host computer and the machine — the image-to-G-code output is streamed wirelessly to the ESP32 rather than requiring a USB connection.

---

## Firmware

This project uses [Grbl_Esp32](https://github.com/bdring/Grbl_Esp32) for motion control. Configuration files and pin mappings will be added once electronics design is finalized.

## Software Pipeline

```
Image → Dithering/Thresholding → Grid Mapping → G-code → ESP32-GRBL → Machine
```

A Python script for image processing and G-code generation is planned.

---

## License

*TBD*

---

## Authors

**Nadec Biju**   - COREXY
- GitHub: [@NB6RULES](https://github.com/NB6RULES)

**Architha B K**  
- GitHub: [@architabk618-hue](https://github.com/architabk618-hue)

**Kurian**   - INTERFACE 
- GitHub: [@Kuriyaappi](https://github.com/Kuriyaappi)

**Kevin J Jijo**  - END E
- GitHub: [@mrkubby](https://github.com/mrkubby)

**Merin Menamparambil**  
- GitHub: [@merinmenamparambil](https://github.com/merinmenamparambil)

## CoreXY References

### [CoreXY.com](https://corexy.com/)
The original reference site documenting the CoreXY motion system concept, belt routing geometry, and kinematics. Used as the primary reference for understanding how the two-motor H-bot style drive works and how to correctly route belts to achieve true CoreXY motion without shear forces.

### [Jubilee (Machine Agency)](https://github.com/machineagency/jubilee)
An open-source CoreXY toolchanging machine designed for research and fabrication. Referenced for its well-engineered CoreXY gantry design, use of 2020 extrusion framing, and modular tool head approach — directly relevant to how we've structured our own gantry and end effector mounting.

---

## Acknowledgments

- Inspired by bead art and CNC plotters
- McMaster-Carr for hardware CAD models
