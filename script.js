let play;

function updateResult(msg) {
    const [status, score, match] = msg.split(" | ");
    document.getElementById("result").textContent = status;
    document.getElementById("score").textContent = score;
    if (match) alert(match);
}

function onMove(move) {
    const result = play(move);
    updateResult(result);
}

Module.onRuntimeInitialized = () => {
    play = Module.cwrap("play", "string", ["number"]);

    document.querySelectorAll("button").forEach((btn, idx) => {
        btn.onclick = () => onMove(idx);
    });
};
