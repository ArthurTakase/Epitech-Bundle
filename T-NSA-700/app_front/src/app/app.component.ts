import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { FormControl } from '@angular/forms';

import { environment } from '../environments/environment';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent implements OnInit {

  public health: object | string = {};
  public healthy: string = null;

  public messages: object[] = [];

  public formError: string = '';

  constructor(private http: HttpClient) { }

  ngOnInit() {
    this.refreshState();
    this.refreshMessages();
    setInterval(() => {
      this.refreshState();
      this.refreshMessages();
    }, 1000);
  }

  private refreshState() {
    this.http.get<object>(environment.api_endpoint + '/health')
      .subscribe(
        (res: object) => {
          this.health = res;
          this.healthy = 'good-job-bro';

          if (!!res['mysql_migrations'] && res['mysql_migrations'] != "healthy")
            this.healthy = 'not-that-bad';
          if (!!res['mysql'] && res['mysql'] != "healthy")
            this.healthy = 'argh';
        },
        (err) => {
          this.health = 'Failed to request backend';
          this.healthy = 'argh';
          console.error(err);
        },
      );
  }

  private refreshMessages() {
    // quick and dirty polling
    this.http.get<object[]>(environment.api_endpoint + '/message')
      .subscribe(
        (messages: object[]) => {
          this.messages = messages;
        },
        (err) => {
          this.messages = [];
          console.error(err);
        },
      );
  }

  public postMessage(data) {
    const body = {
      'username': data['username'],
      'message': data['message'],
    };
    console.log(body);
    this.http.post<object>(environment.api_endpoint + '/message', body)
      .subscribe(
        (messages: object) => {
          this.formError = '';
        },
        (err) => {
          this.formError = err.error.message;
          console.error(err);
        },
      );
  }

}
