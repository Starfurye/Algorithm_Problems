function genRandom(type, config) {
    if (type === "integer") {
        return (
            Math.floor(Math.random() * (config.max - config.min)) + config.min
        );
    }
}

module.exports = genRandom;
