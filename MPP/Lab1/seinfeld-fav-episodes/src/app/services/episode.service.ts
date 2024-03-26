import { Injectable } from '@angular/core';
import { Episode } from "../models/episode";
import { EPISODES } from "../episodes";
import { Observable, of } from "rxjs";

@Injectable({
  providedIn: 'root'
})
export class EpisodeService {

  episodesList: Episode[] = EPISODES;

  getID(title: string | undefined): number {
    for (const episode of this.episodesList) {
      if (title === this.transformString(episode.title))
        return Number(episode.id);
    }
    throw new Error('ID not found!');
  }



  getFreeID(): number {
    let maxId = 0;
    for (const episode of this.episodesList) {
      if (episode.id > maxId) {
        maxId = episode.id;
      }
    }
    return maxId + 1;
  }


  addEpisode(episode: Episode): Observable<Episode> {
    if (!episode) {
      throw new Error('Episode cannot be undefined!');
    }
    episode.id = Number(episode.id);
    episode.season = Number(episode.season);
    episode.ep = Number(episode.ep);
    episode.rating = Number(episode.rating);

    if (episode.title === '') {
      throw new Error('Title can\'t be empty!');
    }

    if (isNaN(episode.id) || isNaN(episode.season) || isNaN(episode.ep) || isNaN(episode.rating)) {
      throw new Error('Invalid episode data!');
    }

    if (this.episodesList.find((e) => e.title === episode.title)) {
      throw new Error('Episode with this title already exists!');
    }

    this.episodesList.push(episode);
    return of(episode);
  }

  getEpisode(id: number): Observable<Episode> {
    const episode = this.episodesList.find(e => e.id === id);
    if (!episode) {
      throw new Error('Episode not found!');
    }
    return of(episode);
  }

  getEpisodes(): Observable<Episode[]> {
    return of(this.episodesList);
  }

  deleteEpisode(epId: number): Observable<void> {
    const epIndex = this.episodesList.findIndex((e) => e.id === epId);
    if (epIndex === -1) {
      throw new Error('Episode does not exist');
    }
    this.episodesList.splice(epIndex, 1);
    return of(undefined);
  }

  getLength(): number {
    return this.episodesList.length;
  }

  transformString(input: string): string {
    let transformedString = input.trim();

    transformedString = transformedString.replace(/\s+/g, '-');

    transformedString = transformedString.toLowerCase();

    return transformedString;
  }

  filterBySeason(season?: number): Observable<Episode[]> {
    if (!season) {
      return of(this.episodesList);
    }
    const filteredEpisode = this.episodesList.filter((e) => e.season === season)
    return of(filteredEpisode)
  }

  searchEpisode(episodeToFind?: string): Observable<Episode[]> {
    if (!episodeToFind) {
      return of(this.episodesList);
    }
    const foundEpisodes = this.episodesList.filter(episode =>
      episode.title.toLowerCase().includes(episodeToFind.toLowerCase())
    );
    return of(foundEpisodes);
  }

  getCountBySeason(season: number): number {
    const count = this.episodesList.filter((e) => (e.season === season)).length;
    return count;
  }
}
