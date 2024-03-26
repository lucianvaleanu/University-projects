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
  pageSize = 12;
  p = 1;


  season?: number;

  episodeToFind?: string;

  constructor(private episodeService: EpisodeService) {
  }

  onSeasonChange(newSeason: number): void {
    this.episodeToFind = undefined;
    this.season = newSeason;
    this.getEpisodes();
  }

  ngOnInit(): void {
    this.getEpisodes();
  }

  searchEpisode(episodeInput: string): void {
    this.season = undefined;
    this.episodeToFind = episodeInput;
    this.getEpisodeFromSearch();
  }

  getEpisodeFromSearch(): void {
    this.episodeService.searchEpisode(this.episodeToFind).subscribe((foundEpisode) => {
      this.episodes = foundEpisode;
    });
  }


  getEpisodes(): void {
    this.episodeService.filterBySeason(Number(this.season)).subscribe((filteredEpisodes) => {
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

  onPageChange(pageNumber: number): void {
    this.p = pageNumber;

  }
}
