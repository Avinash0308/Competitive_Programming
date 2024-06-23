class Person {
  constructor(name, age) {
    const _name = name;
    const _age = age;
    this.getName = function () {
      return _name;
    };
    this.getAge = function () {
      return _age;
    };
  }
}
const person1 = new Person("Alice", 25);
debugger;
console.log(person1.getName());
console.log(person1.getAge());
