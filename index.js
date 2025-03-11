"use strict";

const displays = require("bindings")("displays");

module.exports = () => displays.get().sort((displayA, displayB) =>
    // sort all displays from top to bottom, left to right
    displayA.top - displayB.top || displayA.left - displayB.left);