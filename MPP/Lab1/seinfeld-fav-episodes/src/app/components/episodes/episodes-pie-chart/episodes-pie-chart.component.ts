import { Component, OnInit } from '@angular/core';
import { EpisodeService } from '../../../services/episode.service';
import { Episode } from '../../../models/episode';
import { Color, LegendPosition, ScaleType } from '@swimlane/ngx-charts';


@Component({
  selector: 'app-episodes-pie-chart',
  templateUrl: './episodes-pie-chart.component.html',
  styleUrls: ['./episodes-pie-chart.component.css']
})
export class EpisodesPieChartComponent implements OnInit {

  seasonEpisodeCount: { name: string, value: number }[] = [];
  view: [number, number] = [700, 400];
  colorScheme: Color = {
    name: 'myScheme',
    selectable: true,
    group: ScaleType.Ordinal,
    domain: ['#fa2f2f', '#fa952f', '#c7fa2f', '#2ffa9b', '#2ff0fa', '#2f98fa', '#982ffa', '#e92ffa', '#fa2f62']
  };
  legendPosition: LegendPosition = LegendPosition.Right;

  episodes: Episode[] = [];
  pieChartData: any[] = [];

  constructor(private episodeService: EpisodeService) { }

  ngOnInit(): void {
    this.episodeService.getEpisodes().subscribe(episodes => {
      this.episodes = episodes;
      this.generatePieChartData();
    });
  }

  generatePieChartData(): void {
    const seasonCounts: { [season: number]: number } = {};

    for (const episode of this.episodes) {
      if (seasonCounts.hasOwnProperty(episode.season)) {
        seasonCounts[episode.season]++;
      } else {
        seasonCounts[episode.season] = 1;
      }
    }

    this.pieChartData = Object.keys(seasonCounts).map(season => ({
      name: `Season ${season}`,
      value: seasonCounts[parseInt(season)]
    }));
  }

  onSelect($event: any) {
    throw new Error('Method not implemented.');
    }
}
