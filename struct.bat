@echo off
REM Создание структуры папок

echo Создание папки src...
mkdir src
if not errorlevel 0 (
    echo Ошибка при создании папки src
    goto :end
)

echo Создание файлов в папке src...
type nul > src\main.cpp
type nul > src\GameEngine.cpp
type nul > src\GameEngine.h
type nul > src\MazeGenerator.cpp
type nul > src\MazeGenerator.h
type nul > src\Player.cpp
type nul > src\Player.h
type nul > src\Enemy.cpp
type nul > src\Enemy.h
type nul > src\Artifact.cpp
type nul > src\Artifact.h
type nul > src\InputManager.cpp
type nul > src\InputManager.h
type nul > src\Renderer.cpp
type nul > src\Renderer.h
type nul > src\AudioManager.cpp
type nul > src\AudioManager.h
type nul > src\UIManager.cpp
type nul > src\UIManager.h
type nul > src\PhysicsEngine.cpp
type nul > src\PhysicsEngine.h
type nul > src\Utils.cpp
type nul > src\Utils.h

if not errorlevel 0 (
    echo Ошибка при создании файлов в папке src
    goto :end
)

echo Создание папки include...
mkdir include
if not errorlevel 0 (
    echo Ошибка при создании папки include
    goto :end
)

echo Создание папки SDL2 в include...
mkdir include\SDL2
if not errorlevel 0 (
    echo Ошибка при создании папки SDL2
    goto :end
)

echo Создание папки SDL2_mixer в include...
mkdir include\SDL2_mixer
if not errorlevel 0 (
    echo Ошибка при создании папки SDL2_mixer
    goto :end
)

echo Создание папки assets...
mkdir assets
if not errorlevel 0 (
    echo Ошибка при создании папки assets
    goto :end
)

echo Создание папок в папке assets...
mkdir assets\models
mkdir assets\textures
mkdir assets\sounds
mkdir assets\music
mkdir assets\fonts
if not errorlevel 0 (
   echo Ошибка при создании папок в папке assets
   goto :end
)


echo Создание папки docs...
mkdir docs
if not errorlevel 0 (
    echo Ошибка при создании папки docs
    goto :end
)

echo Создание файлов в папке docs...
type nul > docs\design_document.md
type nul > docs\development_plan.md
if not errorlevel 0 (
    echo Ошибка при создании файлов в папке docs
    goto :end
)

echo Создание файла CMakeLists.txt...
type nul > CMakeLists.txt
if not errorlevel 0 (
    echo Ошибка при создании файла CMakeLists.txt
    goto :end
)

echo Структура папок создана успешно.

:end
pause

