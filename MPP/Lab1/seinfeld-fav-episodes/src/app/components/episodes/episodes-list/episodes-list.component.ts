import { Component, SimpleChanges } from '@angular/core';
import { Episode } from "../../../models/episode";
import { EpisodeService } from "../../../services/episode.service";

@Component({
  selector: 'app-episodes',
  templateUrl: './episodes-list.component.html',
  styleUrls: ['./episodes-list.component.css']
})
export class EpisodesComponent {



  episodes: Episode[] = [];

  season?: number

  constructor(private episodeService: EpisodeService) {
  }

  onSeasonChange(newSeason: number): void {
    this.season = newSeason;
    this.getEpisodes();
  }

  ngOnInit(): void {
    this.getEpisodes();
  }


  getEpisodes(): void {
    this.episodeService.fitlerBySeason(Number(this.season)).subscribe((filteredEpisodes) => {
      this.episodes = filteredEpisodes
      //Unsubscribe-ul se face automat cand e distrusa componenta
    });
  }

  transformString(input: string): string {
    let transformedString = input.trim();

    transformedString = transformedString.replace(/\s+/g, '-');

    transformedString = transformedString.toLowerCase();

    return transformedString;
  }
}
