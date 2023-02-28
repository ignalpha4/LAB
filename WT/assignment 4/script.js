let result = document.getElementById('result');

function getResult(val) {
  result.value += val;
}

function clearResult() {
  result.value = '';
}

function calculateResult() {
  try {
    result.value = eval(result.value);
  } catch(err) {
    alert('Invalid calculation');
  }
}
