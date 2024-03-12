import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';

import { EpisodesComponent } from './components/episodes/episodes-list/episodes-list.component';
import { DashboardComponent } from './components/dashboard/dashboard.component';
import { EpisodeDetailComponent } from './components/episodes/episode-detail/episode-detail.component';
import { EpisodeAddComponent } from './components/episodes/episode-add/episode-add.component';
import { EpisodeDeleteComponent } from './components/episodes/episode-delete/episode-delete.component';

const routes: Routes = [
  { path: '', redirectTo: '/dashboard', pathMatch: 'full' },
  { path: 'dashboard', component: DashboardComponent },
  { path: 'detail/:title', component: EpisodeDetailComponent },
  { path: 'episodes/delete/:title', component: EpisodeDeleteComponent},
  { path: 'episodes', component: EpisodesComponent },
  { path: 'episodes/add', component: EpisodeAddComponent}];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
