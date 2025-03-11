"use strict";

const assert = require("assert");
const displays = require("./index")();

console.log("got displays", displays);

assert(displays.length > 0, "Expected at least one display");
assert(displays.every(display => display.top >= 0), "Expected all displays to have a non-negative top attribute");
assert(displays.every(display => display.left >= 0), "Expected all displays to have a non-negative left attribute");
assert(displays.every(display => display.width > 0), "Expected all displays to have a greater-than-zero width attribute");
assert(displays.every(display => display.height > 0), "Expected all displays to have a greater-than-zero height attribute");

console.log("\x1b[32m%s\x1b[0m", "tests passed");