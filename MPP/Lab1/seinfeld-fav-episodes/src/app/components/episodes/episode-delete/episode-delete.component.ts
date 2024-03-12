import { Component, Input } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { Location } from '@angular/common';

import { Episode } from "../../../models/episode";

import { EpisodeService } from '../../../services/episode.service';

@Component({
  selector: 'app-episode-delete',
  templateUrl: './episode-delete.component.html',
  styleUrl: './episode-delete.component.css'
})
export class EpisodeDeleteComponent {

  title?: string;


  constructor(
    private route: ActivatedRoute,
    private episodeService: EpisodeService,
    private location: Location
  ) { }

  ngOnInit(): void {
    this.title = String(this.route.snapshot.paramMap.get('title'));
  }

  onConfirm(): void {
    const id = this.episodeService.getID(this.title);
    if (this.title) {
      this.episodeService.deleteEpisode(id).subscribe(() => {
        this.location.back();
      });
    }
  }

  onCancel() {
    this.location.back();
  }
}
