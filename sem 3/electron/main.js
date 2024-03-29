const { app, BrowserWindow } = require('electron')
const path = require('path');
function createWindow() {
  const window = new BrowserWindow({
    width: 1000,
    height: 800,
    webPreferences: {
        nodeIntegration: true,
        contextIsolation: false,
      preload: path.join(__dirname, 'preload.js'),
	    sandbox: false
    }
  })
  window.loadFile('index.html')
}
app.whenReady().then(() => {
  createWindow()
  app.on('activate', () => {
    if (BrowserWindow.getAllWindows().length === 0) {
      createWindow()
    }
  })
})
app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})
