import { ComponentFixture, TestBed } from '@angular/core/testing';

import { EpisodesPieChartComponent } from './episodes-pie-chart.component';

describe('EpisodesPieChartComponent', () => {
  let component: EpisodesPieChartComponent;
  let fixture: ComponentFixture<EpisodesPieChartComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [EpisodesPieChartComponent]
    })
    .compileComponents();
    
    fixture = TestBed.createComponent(EpisodesPieChartComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
