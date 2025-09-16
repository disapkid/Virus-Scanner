# Virus-Scanner

Virus-Scanner is a lightweight, cross-platform C++ project for detecting potentially malicious files based on signature scanning. Built using CMake, it includes support for unit testing and is structured for clean separation of core logic and interfaces.

---

## 🔧 Features

- Scan individual files or whole directories  
- Use custom or built-in virus/malware signature definitions  
- Modular design: header files (`include/`), core logic (`app/`), tests (`tests/`)  
- Built with CMake for easy building on Windows, Linux, and macOS  

---

## 📁 Project Structure
```
Virus-Scanner/
├── app/ ← Core application logic
├── include/ ← Public headers
├── tests/ ← Unit tests
├── CMakeLists.txt ← Build configuration
└── CMakeSettings.json ← Visual Studio-specific settings (optional)
