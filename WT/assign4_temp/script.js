let result = document.getElementById('result');

function getresult(val) {
  result.value += val;
}

function clearscreen() {
  result.value = '';
}

function output() {
  try {
    result.value = eval(result.value);
  } catch(err) {
    alert('Invalid calculation');
  }
}
