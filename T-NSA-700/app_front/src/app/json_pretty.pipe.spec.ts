import { PrettyPrintPipe } from './json_pretty.pipe';

describe('Pipe: PrettyPrint', () => {
    it('should returns string', () => {
        const pipe = new PrettyPrintPipe();
        expect(pipe.transform({})).toBe("{}");
    });
    it('should returns simple string when value is string', () => {
        const pipe = new PrettyPrintPipe();
        expect(pipe.transform("hello world")).toBe('"hello&nbsp;world"');
    });
    it('should returns pretty printed simple json', () => {
        const pipe = new PrettyPrintPipe();
        expect(pipe.transform({ "hello": "world" })).toBe('{<br>&nbsp;&nbsp;"hello":&nbsp;"world"<br>}');
    });
    it('should returns pretty printed nested json', () => {
        const pipe = new PrettyPrintPipe();
        expect(pipe.transform({ "hello": ["world", "foobar"] })).toBe('{<br>&nbsp;&nbsp;"hello":&nbsp;[<br>&nbsp;&nbsp;&nbsp;&nbsp;"world",<br>&nbsp;&nbsp;&nbsp;&nbsp;"foobar"<br>&nbsp;&nbsp;]<br>}');
    });
});