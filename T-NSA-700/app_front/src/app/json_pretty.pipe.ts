import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
    name: 'json_pretty_print'
})
export class PrettyPrintPipe implements PipeTransform {
    transform(val) {
        return JSON.stringify(val, null, 2)
            .replace(/ /g, '&nbsp;')
            .replace(/\n/g, '<br>');
    }
}
