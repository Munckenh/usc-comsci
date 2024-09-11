<?php

class Car {
    private $brand;
    private $color;
    private $speed;

    function __construct($brand, $color)
    {
        $this->brand = $brand;
        $this->color = $color;
        $this->speed = 0;
    }

    public function accelerate($increase) {
        $this->speed += $increase;
    }

    public function brake($decrease) {
        $this->speed -= $decrease;
        if ($this->speed < 0) {
            $this->speed = 0;
        }
    }

    public function getDetails() {
        return "Brand: $this->brand, Color: $this->color, Speed: $this->speed km/h";
    }
}

$car = new Car("Toyota", "Red");
$car->accelerate(50);
$car->brake(20);
echo $car->getDetails();

?>