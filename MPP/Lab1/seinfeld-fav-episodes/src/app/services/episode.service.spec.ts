import { TestBed } from '@angular/core/testing';
import { of } from 'rxjs';
import { Episode } from '../models/episode';
import { EPISODES } from '../episodes';
import { EpisodeService } from './episode.service';

describe('EpisodeService', () => {
  let service: EpisodeService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(EpisodeService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });

  it('should get episodes', () => {
    const episodes: Episode[] = EPISODES;
    spyOn(service, 'getEpisodes').and.returnValue(of(episodes));

    service.getEpisodes().subscribe(res => {
      expect(res).toEqual(episodes);
    });
  });

  it('should add episode', () => {
    const episodeToAdd: Episode = {
      id: service.getFreeID(),
      title: 'Test Episode',
      season: 1,
      ep: 1,
      rating: 8.5
    };

    spyOn(service, 'addEpisode').and.returnValue(of(episodeToAdd));

    service.addEpisode(episodeToAdd).subscribe(res => {
      expect(res).toEqual(episodeToAdd);
      expect(service.getLength()).toBeGreaterThan(0);
    });
  });

  it('should throw error when adding invalid episode', () => {
    const invalidEpisode: Episode = {
      id: NaN,
      title: 'a',
      season: NaN,
      ep: NaN,
      rating: NaN
    };

    expect(() => service.addEpisode(invalidEpisode)).toThrowError('Invalid episode data!');
  });

  it('should throw error when adding invalid episode', () => {
    const invalidEpisode: Episode = {
      id: NaN,
      title: '',
      season: NaN,
      ep: NaN,
      rating: NaN
    };

    expect(() => service.addEpisode(invalidEpisode)).toThrowError('Title can\'t be empty!');
  });

  it('should delete episode', () => {
    const sizeBeforeDelete=service.getLength();
    service.deleteEpisode(1).subscribe(() => {
      expect(service.getLength()).toBeLessThan(sizeBeforeDelete);
    });
  });

  it('should throw error when getting episode by invalid id', () => {
    const invalidId = -1;
    expect(() => service.getEpisode(invalidId)).toThrowError('Episode not found!');
  });

  it('should filter episodes by season', () => {
    const episodes: Episode[] = [
      { id: 4, title: 'The Comeback', season: 8, ep: 13, rating: 4.2, image: "../assets/thecomeback.jpg" },
      { id: 6, title: 'The Summer of George', season: 8, ep: 22, rating: 5, image: "../assets/thesummerofgeorge.jpg" },
      { id: 8, title: 'The Bizarro Jerry', season: 8, ep: 3, rating: 5, image: "../assets/thebizarrojerry.jpg" }
    ];

    spyOn(service, 'getEpisodes').and.returnValue(of(episodes));

    service.filterBySeason(8).subscribe(filteredEpisodes => {
      expect(filteredEpisodes.length).toBe(4);
      expect(filteredEpisodes.every(episode => episode.season === 8)).toBeTrue();
    });
  });


  it('should return all episodes if no season is given', () => {
    const episodes: Episode[] = EPISODES;

    spyOn(service, 'getEpisodes').and.returnValue(of(episodes));

    service.filterBySeason().subscribe(filteredEpisodes => {
      expect(filteredEpisodes.length).toBe(episodes.length);
    });
  });

  it('should return episodes containing the search term', () => {
    const searchTerm = 'The Soup Nazi';
    service.searchEpisode(searchTerm).subscribe((episodes: Episode[]) => {
      expect(episodes.length).toBe(1);
      expect(episodes[0].title).toContain(searchTerm);
    });
  });

  it('should return empty array if no episodes match the search term', () => {
    const searchTerm = 'Non-existent-Episode';
    service.searchEpisode(searchTerm).subscribe((episodes: Episode[]) => {
      expect(episodes.length).toBe(0);
    });
  });

  it('should return 0 if there are no episodes with the given input season', ()=>{
    const season = 0;
    const count = service.getCountBySeason(season);
    expect(count).toBe(0);
  });

  it('should return 1 if there the given input season is 7', ()=>{
    const season = 7;
    const count = service.getCountBySeason(season);
    expect(count).toBe(1);
  });

});
