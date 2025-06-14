Rock Paper Scissors Game (WASM + C++)

This is a fun Rock-Paper-Scissors game built in **C++** and compiled to **WebAssembly**, playable in any browser!

🎮 Features
- Best of 3 match logic
- Real-time score tracking
- Interactive UI with buttons and images

🚀 Tech Used
- C++ (compiled via Emscripten)
- HTML + CSS + JavaScript
- WebAssembly

🔧 Setup
1. Clone this repo
2. Run `emcc game.cpp -o game.js -s WASM=1 -s "EXPORTED_FUNCTIONS=['_play']" -s "EXPORTED_RUNTIME_METHODS=['cwrap']"`
3. Open `index.html` in a browser

📸 Screenshots
_Add screenshots here_

📦 License
MIT
