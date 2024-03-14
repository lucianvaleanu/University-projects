import { Component, Input } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { Location } from '@angular/common';

import { Episode } from "../../../models/episode";

import { EpisodeService } from '../../../services/episode.service';

@Component({
  selector: 'app-episode-detail',
  templateUrl: './episode-detail.component.html',
  styleUrl: './episode-detail.component.css'
})
export class EpisodeDetailComponent {

  episode?: Episode;

  constructor(
    private route: ActivatedRoute,
    private episodeService: EpisodeService,
    private location: Location
  ) { }

  ngOnInit(): void {
    this.getEpisode();
  }

  onRatingChange(newRating: number) {
    if (this.episode) {
      this.episode.rating = Number(newRating);
    }
  }
  onEpisodeChange(newEpisode: number) {
    if (this.episode) {
      this.episode.ep = Number(newEpisode);
    }
  }
  onSeasonChange(newSeason: number) {
    if (this.episode) {
      this.episode.season = Number(newSeason);
    }
  }

  getEpisode(): void {
    const title = String(this.route.snapshot.paramMap.get('title'));
    const id = this.episodeService.getID(title);
    this.episodeService.getEpisode(id).subscribe(episode => this.episode = episode)

  }

  goBack() {
    this.location.back();
  }
}
