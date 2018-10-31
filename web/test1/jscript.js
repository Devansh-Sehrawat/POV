let bitmap = [ '' , '', '', '' ,''];
let boxbit = [];
let canvasheight = 200  ;
let canvaswidth = 960;
let gridDim = 40;
let boxWidth = canvaswidth/gridDim;
let boxHeight = canvasheight/gridDim;
let boxColors= [];
let colorCheck = false;
console.log(boxWidth);
console.log(boxHeight);

const container = document.querySelector('#container');
container.style.width = `${canvaswidth}px`;
resetBoxes();
resetEventListener();
boxEventListener();
exportData();


for (let i = 0; i < 120; ++i)
    boxbit[i] = 0;

function resetBoxes()
{
    for (let i = 0; i < []; ++i)
        boxbit[i] = 0;

    boxWidth = canvaswidth/gridDim;
    boxHeight = canvasheight/gridDim;

    for (let i = 0; i < boxWidth * boxHeight; ++i)
    {
        const cell = document.createElement("div");
        cell.classList.add("grid");
        cell.id = i.toString();
        cell.style.height = `${gridDim}px`;
        cell.style.width = `${gridDim}px`;
        cell.style.backgroundcolor = "white";
        container.appendChild(cell);
        boxColors.push(128);
    }
}

function deleteBoxes(){
    const boxes = document.getElementsByClassName("grid");
    while(boxes[0])
    {
        boxes[0].parentNode.removeChild(boxes[0]);
    }
}

function changeColor(boxId)
{
    let box = document.getElementById(boxId);
    let red = 255;
    let green = 0;
    let blue = 0;
    let decColor =0x1000000+ blue + 0x100 * green + 0x10000 *red ;

    box.style.backgroundColor = '#'+decColor.toString(16).substr(1);
}

function resetEventListener()
{
const resetButton = document.getElementById("resetButton");
    resetButton.addEventListener("click", (e) =>
    {
        console.log("reseting");
        deleteBoxes();
        resetBoxes();
        boxEventListener();
    });
}

function exportData()
{
const exportButton = document.getElementById("exportButton");
    exportButton.addEventListener("click", (e) =>
    {
        console.log("Doing");
        for (let i = 0; i < 120; ++i)
        {
            if (i >= 0 && i <= 23)
                bitmap[0] += boxbit[i] + '';
            else if (i >= 24 && i <= 47)
                bitmap[1] += boxbit[i] + '';
            else if (i >= 48 && i <= 71)
                bitmap[2] += boxbit[i] + '';
            else if (i >= 72 && i <= 95)
                bitmap[3] += boxbit[i] + '';
            else if (i >= 96 && i <= 119)
                bitmap[4] += boxbit[i] + '';
        }

        var url = "http://192.168.0.23/?user_input=" + bitmap[0] + "&user_input=" + bitmap[1] + "&user_input=" + bitmap[2] + "&user_input="  + bitmap[3] + "&user_input="  + bitmap[4];
        console.log(bitmap[0]);
        console.log(bitmap[1]);
        console.log(bitmap[2]);
        console.log(bitmap[3]);
        console.log(bitmap[4]);
        window.location.href = url;
    });
}

function boxEventListener()
{
    const boxes = document.querySelectorAll(".grid");
    boxes.forEach(box =>
    {
        boxColors[box.id] = 255;
        //boxbit[box.id] = 1;
        box.addEventListener("mousedown", (e) =>
        {
            changeColor(box.id);
            boxbit[box.id] = 1;
        })
    });
}
/*
function colorEventListener(){
  const colorToggle = document.getElementById("colorCheck");
  colorToggle.addEventListener("click", (e) => {
    colorCheck = colorToggle.checked;
  });
}*/
