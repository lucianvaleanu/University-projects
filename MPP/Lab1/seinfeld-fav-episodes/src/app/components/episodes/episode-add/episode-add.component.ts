import { Component } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { EpisodeService } from '../../../services/episode.service';
import { Episode } from '../../../models/episode';
import { Location } from '@angular/common';


@Component({
  selector: 'app-episode-add',
  templateUrl: './episode-add.component.html',
  styleUrl: './episode-add.component.css'
})
export class EpisodeAddComponent {
  episode: Episode = {
    id: 0,
    title: '',
    season: 0,
    ep: 0,
    rating: 0,
    image: "../../../../assets/default.jpg"
  };

  constructor(
    private route: ActivatedRoute,
    private episodeService: EpisodeService,
    private location: Location
  ) {
    this.episode.id = this.episodeService.getFreeID();
  }

  onAdd(): void {
    this.episodeService.addEpisode(this.episode).subscribe(() => {
    });
    this.location.back()
  }

  goBack(): void {
    this.location.back();
  }
}
