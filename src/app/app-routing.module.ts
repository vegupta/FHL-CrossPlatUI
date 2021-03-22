import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { ThreatsComponent } from './threats/threats.component';

const routes: Routes = [
  { path: '', redirectTo: '/AppComponent', pathMatch: 'full' },
  { path: 'threats', component: ThreatsComponent }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule {

}
