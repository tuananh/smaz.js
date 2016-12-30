'use strict';

const assert = require('assert');
const smaz = require('../index');

const test_cases = [
    "This is a small string",
    "foobar",
    "the end",
    // "not-a-g00d-Exampl333",
    "Smaz is a simple compression library",
    "Nothing is more difficult, and therefore more precious, than to be able to decide",
    "this is an example of what works very well with smaz",
    "1000 numbers 2000 will 10 20 30 compress very little",
    "and now a few italian sentences:",
    "Nel mezzo del cammin di nostra vita, mi ritrovai in una selva oscura",
    "Mi illumino di immenso",
    "L'autore di questa libreria vive in Sicilia",
    "try it against urls",
    "http://google.com",
    "http://programming.reddit.com",
    "http://github.com/antirez/smaz/tree/master",
    "/media/hdb1/music/Alben/The Bla",
    "hello world"
];

test_cases.map(function (str) {
    const out = smaz.compress(str);
    const input = smaz.decompress(out);
    assert.strictEqual(true, out.length <= str.length);
    assert.strictEqual(str, input);
});