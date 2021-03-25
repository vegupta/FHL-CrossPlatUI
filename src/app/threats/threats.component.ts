import { Component, OnChanges, OnInit } from '@angular/core';
import { ElectronService } from 'ngx-electron';
import {threat} from '../models/threat'
import { ClrDatagridStateInterface } from '@clr/angular';

@Component({
  selector: 'app-threats',
  templateUrl: './threats.component.html',
  styleUrls: ['./threats.component.css']
})
export class ThreatsComponent implements OnInit, OnChanges {
  loading =true;
  threats : threat[];/* = [

    {
      name: 'EICAR',
      status: 'Quarantined',
      path: '/tmp/eicar.txt'
    },
    {
      name: 'EICAR - TEST',
      status: 'Removed',
      path: '/tmporaryDir/example.txt'
    }
  ];*/

 
  constructor(private _electronService: ElectronService) {
    
/*     this._electronService.ipcRenderer.on('synchronous-reply', (event, arg) => {
      console.log("threat component:"+ arg)
      let th: threat[] = JSON.parse(arg)
      console.log("after parsing"+th);
      this.threats.concat(th);
    }); */
    
  }

  ngOnInit(): void {
    this.refresh(null);
    //this.threats = [];
    //console.log("pinging..");
    //let data = this._electronService.ipcRenderer.sendSync('synchronous-message', 'ping')
    //console.log("threat component:"+ data)
    //let th: threat[] = JSON.parse(data)
    //console.log("after parsing"+th);
  //  this.threats.concat(th);
   
  }
  ngOnChanges():void{
    
  }

  refresh(state: ClrDatagridStateInterface) {
    this.loading = true;
    this.threats = [];
    //console.log(" on changes pinging..");
    
    let data = this._electronService.ipcRenderer.sendSync('synchronous-message', 'ping')
    //console.log("before parsing"+JSON.stringify(data));
    
    let th: threat[] = data;//JSON.parse(JSON.stringify(data));
    //console.log("after parsing"+JSON.stringify(th));
    
    this.threats= th;
    this.loading=false;

    const myNotification = new Notification('Microsoft Defender ATP', {
      body: 'microsoft Defender Detected new threats',
    })
  }
}
