const socket = io();
const terminal = document.getElementById('terminal');
const manualInput = document.getElementById('manual-input');
const statusIndicator = document.getElementById('status-indicator');

// Connect to the backend
socket.on('connect', () => {
    console.log('Connected to server');
    statusIndicator.classList.remove('text-red-500');
    statusIndicator.classList.add('text-green-500');
    statusIndicator.innerText = "● ONLINE";
    
    // Start the C++ session immediately on load
    socket.emit('start-session');
});

socket.on('disconnect', () => {
    console.log('Disconnected');
    statusIndicator.classList.remove('text-green-500');
    statusIndicator.classList.add('text-red-500');
    statusIndicator.innerText = "● OFFLINE";
});

// Handle incoming terminal data
socket.on('terminal-output', (data) => {
    // Append data to terminal
    const span = document.createElement('span');
    span.textContent = data;
    terminal.appendChild(span);
    
    // Auto-scroll to bottom
    terminal.scrollTop = terminal.scrollHeight;
    
    // Limit terminal history (optional, to prevent memory issues)
    if (terminal.childElementCount > 1000) {
        terminal.removeChild(terminal.firstChild);
    }
});

// Send commands
function sendCommand(cmd) {
    socket.emit('send-input', cmd);
}

// Manual Input Handling
function sendManualInput() {
    const val = manualInput.value;
    if (val) {
        sendCommand(val);
        manualInput.value = '';
    }
}

manualInput.addEventListener('keypress', (e) => {
    if (e.key === 'Enter') {
        sendManualInput();
    }
});

document.getElementById('reset-btn').addEventListener('click', () => {
    terminal.innerHTML = '';
    socket.emit('start-session');
});
