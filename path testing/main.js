console.log("Main script loaded")
import BezierPath from './bezierPath';

let elt = document.getElementById("calculator");
const calculator = Desmos.GraphingCalculator(elt);
let paths = [];

// let degree = 4;
// calculator.setExpression({
//     id: "degree",
//     latex: `n=${degree}`,
//     sliderBounds: {
//         min: '1',
//         max: '20',
//         step: '1'
//     }
// });
// let n = calculator.HelperExpression({ latex: 'n' });

// let controlPts = [];
// let ptList = [], points = "";
// for(let i = 0; i < degree + 1; i++) {
//     addPoint(i);
// }

// updateDegree();

// calculator.setExpression({
//     id: "curve",
//     latex: '(B_{x}(t), B_{y}(t))',
//     color: Desmos.Colors.BLUE,
//     parametricDomain: {
//         min: '0',
//         max: '1'
//     }
// });

// n.observe('numericValue', updateDegree);

// fixPtList();

// async function updateDegree() {
//     degree = n.numericValue;
//     if (degree > controlPts.length - 1) {
//         for (let i = controlPts.length; i <= degree; i++) {
//             addPoint(i);
//         }
//     }
//     else if (degree < controlPts.length - 1) {
//         for (let i = controlPts.length - 1; i > degree; i--) {
//             calculator.removeExpression({ id: `x${i + 1}` });
//             calculator.removeExpression({ id: `y${i + 1}` });
//             calculator.removeExpression({ id: `ordpair${i + 1}` });
//             controlPts.pop();
//             ptList.pop();
//         }
//         fixPtList();
//     }
//     let exprX = [];
//     let exprY = [];
//     for(let i = 0; i < degree + 1; i++) {
//         let coeff = calculator.HelperExpression({ latex: `\\frac{${degree}!}{${i}!(${degree - i})!}` });
//         await new Promise(resolve => setTimeout(resolve, 100));
//         let str = `${coeff.numericValue}\\cdot (t^{${i}})\\cdot ((1-t)^{${degree - i}})\\cdot `;
//         exprX.push(str + `(x_{${i + 1}})`);
//         exprY.push(str + `(y_{${i + 1}})`);
//     }
//     calculator.setExpression({id: "exprX", latex: `B_{x}(t)=${exprX.join("+")}`, hidden: true});
//     calculator.setExpression({id: "exprY", latex: `B_{y}(t)=${exprY.join("+")}`, hidden: true});
// }

// function addPoint(i) {
//     controlPts.push([i, i]);
//     calculator.setExpression({id: `x${i + 1}`, latex: `x_{${i + 1}} = ${controlPts[i][0]}`});
//     calculator.setExpression({id: `y${i + 1}`, latex: `y_{${i + 1}} = ${controlPts[i][1]}`});
//     calculator.setExpression({id: `ordpair${i + 1}`, latex: `p_{${i + 1}}=(x_{${i + 1}},y_{${i + 1}})`, color: Desmos.Colors.BLACK});
    
//     ptList.push(`(x_{${i + 1}},y_{${i + 1}})`);
//     fixPtList();
// }

// function fixPtList() {
//     points = ptList.join(",");
//     calculator.setExpression({
//         id: "ptlist",
//         latex: points,
//         lines: true,
//         lineStyle: Desmos.Styles.DOTTED,
//         color: Desmos.Colors.RED
//     });
// }

const l = new BezierPath(1, 4);
paths.push(l);



function setExpression(name, expression, params) {
    params.id = name;
    params.latex = expression;
    calculator.setExpression(params);
}