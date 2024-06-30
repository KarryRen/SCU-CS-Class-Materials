package com.example.software;

 import lombok.extern.slf4j.Slf4j;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.web.servlet.ServletComponentScan;

 @Slf4j
@ServletComponentScan
@SpringBootApplication
public class SoftWare {

    public static void main(String[] args) {

        SpringApplication.run(SoftWare.class, args);
         log.info("server starts!");
    }

}
