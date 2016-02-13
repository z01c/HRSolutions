var iMax = 10;
var jMax = 10;
var visited = new Array();

for (i=0;i<iMax;i++) {
 visited[i]=new Array();
 for (j=0;j<jMax;j++) {
  visited[i][j]=0;
 }
}

function findZoneHelper(grid, i, j, count, M, N) {
        if(i < 0 || j < 0 || i >= M || j >= N) return 0;
        if(visited[i][j]) return 0;
        visited[i][j] = 1;
        if(grid[i][j] == 0) return 0;
        else return 1 +
            findZoneHelper(grid, i-1, j-1, count, M, N) +
            findZoneHelper(grid, i-1, j, count, M, N) + 
            findZoneHelper(grid, i-1, j+1, count, M, N) + 
            findZoneHelper(grid, i, j-1, count, M, N) + 
            findZoneHelper(grid, i, j, count, M, N) + 
            findZoneHelper(grid, i, j+1, count, M, N) + 
            findZoneHelper(grid, i+1, j-1, count, M, N) + 
            findZoneHelper(grid, i+1, j, count, M, N) + 
            findZoneHelper(grid, i+1, j+1, count, M, N);
    }


function processData(input) {
    var rows = input.split('\n');
    var m = rows[0].split(' ').map(Number);
    var n = rows[1].split(' ').map(Number);
    var arr = new Array(m);
    for (var i = 0; i < m; i++) {
        arr[i] = new Array(n);
        for (var j = 0; j < n; j++) {
            arr[i][j] = rows[i+2].split(' ').map(Number)[j];
        }
    }
    //console.log(arr);
    var max = 0;
    for(var i = 0; i < m; i++) {
        for(var j = 0; j < n; j++) {
            if(!visited[i][j]) max = Math.max(max, findZoneHelper(arr, i, j, 0, m, n));
       }
    }
    console.log(max);
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
