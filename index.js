'use strict';

const smaz = require('./build/Release/smaz.js');

module.exports = {
    compress: function(input) {
        if (typeof input === 'string' && input.length > 0) {
            return smaz.compress(new Buffer.from(input));
        }

        throw new Error('Expected a non-empty string');
    },
    decompress: function(input) {
        if (Buffer.isBuffer(input) && input.length > 0) {
            return smaz.decompress(input).toString();
        }
        throw new Error('Expected a non-empty Buffer');
    }
};
