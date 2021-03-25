const {app, BrowserWindow,ipcMain, Menu} = require('electron')
    const url = require("url");
    const path = require("path");

    let mainWindow

    function createWindow () {
      mainWindow = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
          nodeIntegration: true,
          contextIsolation: false
        }
      })

      mainWindow.loadURL(
        url.format({
          pathname: path.join(__dirname, `/dist/index.html`),
          protocol: "file:",
          slashes: true
        })
      );
      // Open the DevTools.
      //mainWindow.webContents.openDevTools()
      Menu.setApplicationMenu(null)
      mainWindow.on('closed', function () {
        mainWindow = null
      })
    }

    app.on('ready', createWindow)

    app.on('window-all-closed', function () {
      if (process.platform !== 'darwin') app.quit()
    })

    app.on('activate', function () {
      if (mainWindow === null) createWindow()
    })

    const EventEmitter = require('events').EventEmitter;
    const { JsonFormatter } = require('tslint/lib/formatters');
    const addon = require('bindings')('emit_from_cpp')
    data = 'abc'
    const emitter = new EventEmitter()
    emitter.on('data', (evt) => {
        console.log("got data from addon:")
        //console.log(evt);
        data = evt 
    })

    ipcMain.on('synchronous-message', (event, arg) => {
      console.log(arg) // prints "ping"
      addon.callEmit(emitter.emit.bind(emitter))
      //console.log("repling with"+JSON.stringify(data));
      //event.reply('synchronous-reply', data)
      event.returnValue = data;
      //console.log(event)
    }) 