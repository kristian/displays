[<img width="300" alt="Displays Logo" src="https://raw.githubusercontent.com/kristian/displays/master/logo.svg?sanitize=true">](https://github.com/kristian/displays#readme)

`displays` is a native cross-platform Node.js module for Windows, Linux / X11 and macOS / OSX for retrieving the resolution and position of all connected and active displays / monitors / screens.

## Usage

See [`test.js`](test.js), for an example on how to retrieve all connected displays:

```js
const displays = require("displays")();
console.log("got displays", displays);
```

This will output:

```
got displays [
    Display { top: 0, left: 0, width: 1920, height: 1080 },
    Display { top: 0, left: 1920, width: 800, height: 600 }
]
```

## Installation

This is a [Node.js](https://nodejs.org/en/) module available through the
[npm registry](https://www.npmjs.com/). Install it using:

```
$ npm install displays
```

Before installing, [download and install Node.js](https://nodejs.org/en/download/).
Node.js 12 is recommended.

## Author

Written by [Kristian Kraljić](https://kra.lc/).

## Reporting bugs

Please file any issues [on Github](https://github.com/kristian/displays/issues).

## License

This library is licensed under the [MIT](LICENSE) license.