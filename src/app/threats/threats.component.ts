import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-threats',
  templateUrl: './threats.component.html',
  styleUrls: ['./threats.component.css']
})
export class ThreatsComponent implements OnInit {

  threats = [
    {
      name: 'EICAR',
      status: 'Quarantined',
      affectedResources: [
      '/tmp/eicar.txt']
    },
    {
      name: 'EICAR - TEST',
      status: 'Removed',
      affectedResources: [
      '/Downloads/testDir/eicar.txt',
      '/tmporaryDir/example.txt'
      ]
    }
  ];
  constructor() {
  }

  ngOnInit(): void {
  }

}
