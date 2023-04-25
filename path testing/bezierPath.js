export class BezierPath {
    constructor(id, degree) {
        console.log("Bezier path loaded");
        this.degree = 0;
        this.controlPts = [];
        this.handles = [];
        this.id = id;
        this.setDegree(degree);
    }

    binomialCoeff(n, k) {
        let r = 1;
        if (k > n - k) k = n - k;
        for (let i = 0; i < k; i++) {
            r *= (n - i);
            r /= (i + 1);
        }
        return r;
    }

    setDegree(i) {
        this.degree = i;
        if (this.controlPts.length - 1 < i) { addPoints(); }
        else if (this.controlPts.length - 1 > i) { removePoints(); }
    }

    addPoints() {
        for (let i = this.controlPts.length; i <= this.degree; i++) {
            this.controlPts.push([i, i]);
            this.handles.push(`(x_{${i + 1}x${this.id}},y_{${i + 1}x${this.id}})`);
        }
    }

    removePoints() {
        for (let i = this.controlPts.length; i > this.degree + 1; i++) {
            this.controlPts.pop();
            this.handles.pop();
        }
    }

    getExpressions() {
        let exprX = [], exprY = [];
        for (let i = 0; i <= this.degree; i++) {
            let coeff = this.binomialCoeff(this.degree, i);
            let str = `${coeff}(t^{${i}})((1-t)^{${degree - i}})\\cdot `;
            exprX.push(str + `(x_{${i + 1}x${this.id}})`);
            exprY.push(str + `(y_{${i + 1}x${this.id}})`);
        }
        return { x: `B_{x${this.id}}(t)=${exprX.join("+")}`, y: `B_{y${this.id}}(t)=${exprY.join("+")}`, h: this.handles };
    }
}