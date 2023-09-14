console.clear();

const pieceTypeL = (columns, base, occurrencesBase, basePosition) => {
  let nodesMinHeight = Math.min(...columns.filter((n) => n !== base));
  if (occurrencesBase === 1 && columns[basePosition - 1] === 2) {
    return "TODO";
  } else if (occurrencesBase === 1) {
    return "TODO";
  } else {
    return 0;
  }
};

const pieceTypeJ = (columns, base, occurrencesBase, basePosition) => {
  if (
    occurrencesBase === 2 &&
    (columns[basePosition + 1] === base || columns[basePosition - 1] === base)
  ) {
    return 1;
  } else if (occurrencesBase === 1) {
    let borderMinHeight =
      columns[basePosition - 1] < columns[basePosition + 1]
        ? columns[basePosition - 1]
        : columns[basePosition + 1];
    let nodesMinHeight = Math.min(...columns.filter((n) => n !== base));
    if (nodesMinHeight >= borderMinHeight) {
      return 1;
    } else {
      return 0;
    }
  } else {
    return 0;
  }
};

const pieceTypeI = (columns, base, occurrencesBase) => {
  if (occurrencesBase === 1) {
    return Math.min(...columns.filter((n) => n !== base));
  } else {
    return 0;
  }
};

const processPiece = (piece, columns, base, occurrencesBase, basePosition) => {
  switch (piece) {
    case "I":
      return pieceTypeI(columns, base, occurrencesBase);

    case "J":
      return pieceTypeJ(columns, base, occurrencesBase, basePosition);

    default:
      return 0;
  }
};

const TetrisMove = (strArr) => {
  let { piece, columns } = ((arr) => {
    return { piece: arr.shift(), columns: arr.map(Number) };
  })(strArr);

  let base = Math.min(...strArr);
  let occurrencesBase = columns.filter((n) => n === base).length;

  let basePosition = columns.indexOf(base);
  let baseSize =
    occurrencesBase >= 2 &&
    (columns[basePosition - 1] === base || columns[basePosition + 1] === base);

 

  if (occurrencesBase >= 1 && occurrencesBase < 3) {
    return processPiece(piece, columns, base, occurrencesBase, basePosition);
  } else {
    return 0;
  }
};

let inputL = ["L", "3", "4", "4", "5", "6", "2", "0", "6", "5", "3", "6", "6"];
let inputI = ["I", "2", "4", "3", "4", "5", "2", "0", "2", "2", "3", "3", "3"];
let inputO = ["O", "4", "3", "2", "3", "5", "1", "0", "1", "2", "4", "3", "4"];

let inputJ = ["J", "5", "6", "7", "8", "6", "7", "0", "5", "5", "8", "7", "9"];

console.log("Answer: ", TetrisMove(inputI));