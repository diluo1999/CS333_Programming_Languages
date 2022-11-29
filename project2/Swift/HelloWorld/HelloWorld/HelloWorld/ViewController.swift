/**
* CS333 Project 2
* ViewController.swift
* Create a Hello World App with Swift
* Di Luo
* 03/01/2020
*/
//  ViewController.swift
//  HelloWorld
//
//  Created by Di Luo on 2020/3/1.
//  Copyright © 2020 Di Luo. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func helloWorldAction(_ sender: Any) {
        print("Hello, World!")
    }
}

