const product_list = document.getElementById("product-list");
const item_list = document.getElementById("item-list");
let sum = 0;
let items = {};
let products = {
    "1": 50,
    "2": 12,
    "3": 63,
    "4": 24,
    "5": 92,
    "6": 100,
    "7": 256,
    "8": 75,
    "9": 20,
    "10": 5,
};

function clear() {
    product_list.innerHTML = "";
    item_list.innerHTML = "";
}

function update() {
    sum = 0;
    for (const [key, value] of Object.entries(products)) {
        let product = document.createElement("li");
        product.innerHTML = `
            Product ${key.padStart(2, "0")}: ₱${value}</br>
            <button onclick="add(${key}, ${value})">Add</button>
        `;
        product_list.appendChild(product);
    }
    for (const [key, value] of Object.entries(items)) {
        sum += value;
        let item = document.createElement("li");
        item.innerHTML = `
            Product ${key.padStart(2, "0")}: ₱${value}</br>
            <button onclick="remove(${key}, ${value})">Remove</button>
        `;
        item_list.appendChild(item);
    }
    document.getElementById("sum").setAttribute("value", sum);
}

function tender() {
    let cash = document.getElementById("cash").value;
    if (cash != "") {
        if (cash < sum) {
            alert("Insufficient funds!");
        } else {
            alert(`Your change is ₱${cash - sum}.00`);
            items = {};
            document.getElementById("cash").value = 0;
            clear();
            update();
        }
    }
}

function remove(key, value) {
    delete items[key];
    products[key] = value;
    clear();
    update();
}

function add(key, value) {
    delete products[key];
    items[key] = value;
    clear();
    update();
}

update();