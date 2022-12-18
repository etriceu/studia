const { contextBridge } = require('electron');
const fs = require('fs');
 contextBridge.exposeInMainWorld('api', {
   readFile: function (filePath) {
    return fs.readFileSync(filePath, 'utf8');
  }
 });
