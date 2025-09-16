# Virus-Scanner

Virus-Scanner is a lightweight, cross-platform C++ project for detecting potentially malicious files based on signature scanning.  
The project demonstrates **multithreaded programming** for parallel file scanning and includes a **custom DLL library** for reusable scanning logic.  
It is built using **CMake** and is compatible with Windows (Visual Studio), Linux, and macOS.

---

## 🔧 Features

- Multithreaded scanning: files and directories are processed in parallel for better performance  
- Custom DLL library with reusable scanning functions  
- Scan individual files or whole directories  
- Modular design: header files (`include/`), core logic (`app/`), tests (`tests/`)  
- Built with **CMake** for cross-platform building  

---

## 📁 Project Structure


```
Virus-Scanner/
├── app/ ← Core application logic
├── include/ ← Public headers
├── tests/ ← Unit tests
├── CMakeLists.txt ← Build configuration
└── CMakeSettings.json ← Visual Studio-specific settings (optional)
