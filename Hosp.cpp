#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Base class for a person
class Person {
public:
    Person(const std::string& name, int age, const std::string& mobile, const std::string& city)
        : name(name), age(age), mobile(mobile), city(city) {}
    virtual void displayInfo() const = 0; // Pure virtual function
    virtual ~Person() {}

protected:
    std::string name;
    int age;
    std::string mobile;
    std::string city;
};

// Derived class for Patient
class Patient : public Person {
public:
    Patient(const std::string& name, int age, const std::string& mobile, const std::string& city, const std::string& disease)
        : Person(name, age, mobile, city), disease(disease) {}

    void displayInfo() const override {
        std::cout << "Patient Name: " << name << "\n"
                  << "Age: " << age << "\n"
                  << "Mobile No: " << mobile << "\n"
                  << "City: " << city << "\n"
                  << "Disease: " << disease << std::endl;
    }

    std::string getDisease() const {
        return disease;
    }

private:
    std::string disease;
};

// Hospital class to manage hospital information
class Hospital {
public:
    Hospital(const std::string& name, const std::string& location, const std::string& specialization, const std::string& doctorName)
        : name(name), location(location), specialization(specialization), doctorName(doctorName) {}

    std::string getSpecialization() const {
        return specialization;
    }

    std::string getName() const {
        return name;
    }

    std::string getLocation() const {
        return location;
    }

    std::string getDoctorName() const {
        return doctorName;
    }

private:
    std::string name;
    std::string location;
    std::string specialization;
    std::string doctorName;
};

// Function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to recommend a hospital and doctor based on the patient's disease
void recommendHospital(const Patient& patient) {
    std::string disease = toLower(patient.getDisease());
    std::vector<Hospital> hospitals = {
        Hospital("Lung Health Center", "123 Lung St.", "oncology", "Dr. Smith"),
        Hospital("Blood Disorders Hospital", "456 Blood Ave.", "hematology", "Dr. Johnson"),
        Hospital("Skin Care Clinic", "789 Skin Blvd.", "dermatology", "Dr. Brown"),
        Hospital("General Health Hospital", "101 Health Rd.", "general", "Dr. Green"),
        Hospital("Respiratory Care Unit", "321 Resp St.", "pulmonology", "Dr. White"),
        Hospital("Diabetes Care Center", "555 Diabetes St.", "endocrinology", "Dr. Taylor"),
        Hospital("Cardiac Health Institute", "777 Heart St.", "cardiology", "Dr. Martinez"),
        Hospital("Infectious Disease Hospital", "888 Virus Ave.", "infectious diseases", "Dr. Adams"),
        Hospital("Kidney Health Center", "222 Kidney Blvd.", "nephrology", "Dr. Lee"),
        Hospital("Arthritis Clinic", "333 Joint St.", "rheumatology", "Dr. Davis"),
        Hospital("Alzheimer's Care Facility", "444 Memory Ln.", "neurology", "Dr. Harris")
    };

    std::string recommendedHospital;
    std::string location;
    std::string doctorName;

    for (const auto& hospital : hospitals) {
        if ((disease == "lung cancer" && hospital.getSpecialization() == "oncology") ||
            (disease == "blood cancer" && hospital.getSpecialization() == "hematology") ||
            (disease == "skin disease" && hospital.getSpecialization() == "dermatology") ||
            (disease == "corona" && hospital.getSpecialization() == "pulmonology") ||
            (disease == "diabetes" && hospital.getSpecialization() == "endocrinology") ||
            (disease == "heart disease" && hospital.getSpecialization() == "cardiology") ||
            (disease == "hiv/aids" && hospital.getSpecialization() == "infectious diseases") ||
            (disease == "tuberculosis" && hospital.getSpecialization() == "infectious diseases") ||
            (disease == "asthma" && hospital.getSpecialization() == "pulmonology") ||
            (disease == "chronic kidney disease" && hospital.getSpecialization() == "nephrology") ||
            (disease == "arthritis" && hospital.getSpecialization() == "rheumatology") ||
            (disease == "alzheimer's disease" && hospital.getSpecialization() == "neurology")) {
            recommendedHospital = hospital.getName();
            location = hospital.getLocation();
            doctorName = hospital.getDoctorName();
            break;
        }
    }

    if (!recommendedHospital.empty()) {
        std::cout << "Recommended Hospital: " << recommendedHospital << "\n"
                  << "Location: " << location << "\n"
                  << "Doctor: " << doctorName << std::endl;
    } else {
        std::cout << "No suitable hospital found for the disease." << std::endl;
    }
}

int main() {
    // User input for patient details
    std::string patientName;
    int patientAge;
    std::string patientMobile;
    std::string patientCity;
    std::string patientDisease;

    std::cout << "Enter Patient Name: ";
    std::getline(std::cin, patientName);
    std::cout << "Enter Patient Age: ";
    std::cin >> patientAge;
    std::cin.ignore(); // Clear the newline from the input buffer
    std::cout << "Enter Patient Mobile No: ";
    std::getline(std::cin, patientMobile);
    std::cout << "Enter Patient City: ";
    std::getline(std::cin, patientCity);
    std::cout << "Enter Patient Disease (e.g., Lung Cancer, Blood Cancer, Skin Disease, Corona, Diabetes, Heart Disease, HIV/AIDS, Tuberculosis, Asthma, Chronic Kidney Disease, Arthritis, Alzheimer's Disease): ";
    std::getline(std::cin, patientDisease);

    Patient newPatient(patientName, patientAge, patientMobile, patientCity, patientDisease);
    
    // Display patient information
    newPatient.displayInfo();
    
    // Recommend a hospital and doctor
    recommendHospital(newPatient);

    return 0;
}