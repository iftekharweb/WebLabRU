
// let clickableDiv = document.getElementById('clickit');

// clickableDiv.addEventListener('click', function ah() {
//     // Create a new div for the description
//     var descriptionDiv = document.createElement('div');
//     descriptionDiv.style.width = '100%';
//     descriptionDiv.style.height = '100vh';
//     descriptionDiv.style.backgroundColor = 'lightcoral';
//     descriptionDiv.textContent = 'This is the description div added after clicking the first div.';

//     // Append the new description div after the clickable div
//     clickableDiv.insertAdjacentElement('afterend', descriptionDiv);
// });

let clickableDiv = document.getElementById('clickit');

clickableDiv.addEventListener('click', () => {
    alert('This A a laptop with code');
})

function handleClick () {
    alert('This A a laptop with code');
}
