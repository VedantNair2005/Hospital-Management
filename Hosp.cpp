#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Base class for a person
class Person {
public:
    Person(const string& name, int age, const string& mobile, const string& city)
        : name(name), age(age), mobile(mobile), city(city) {}
    virtual void displayInfo() const = 0; // Pure virtual function
    virtual ~Person() {}

protected:
    string name;
    int age;
    string mobile;
    string city;
};

// Derived class for Patient
class Patient : public Person {
public:
    Patient(const string& name, int age, const string& mobile, const string& city, const string& disease)
        : Person(name, age, mobile, city), disease(disease) {}

    void displayInfo() const override {
        cout << "Patient Name: " << name << "\n"
             << "Age: " << age << "\n"
             << "Mobile No: " << mobile << "\n"
             << "City: " << city << "\n"
             << "Disease: " << disease << endl;
    }

    string getDisease() const {
        return disease;
    }

private:
    string disease;
};

// Hospital class to manage hospital information
class Hospital {
public:
    Hospital(const string& name, const string& location, const string& specialization, const string& doctorName)
        : name(name), location(location), specialization(specialization), doctorName(doctorName) {}

    string getSpecialization() const {
        return specialization;
    }

    string getName() const {
        return name;
    }

    string getLocation() const {
        return location;
    }

    string getDoctorName() const {
        return doctorName;
    }

private:
    string name;
    string location;
    string specialization;
    string doctorName;
};

// Function to convert a string to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to recommend a hospital and doctor based on the patient's disease
void recommendHospital(const Patient& patient) {
    string disease = toLower(patient.getDisease());
    vector<Hospital> hospitals = {
        Hospital("Lung Health Center", "Surya hospital.", "oncology", "Dr. Smith"),
        Hospital("Blood Disorders Hospital", "456  Ave.", "hematology", "Dr. Johnson"),
        Hospital("Skin Care Clinic", "789  Blvd.", "dermatology", "Dr. Brown"),
        Hospital("General Health Hospital", "101 Health Rd.", "general", "Dr. Green"),
        Hospital("Respiratory Care Unit", "321  St.", "pulmonology", "Dr. White"),
        Hospital("Diabetes Care Center", "555  St.", "endocrinology", "Dr. Taylor"),
        Hospital("Cardiac Health Institute", "777  St.", "cardiology", "Dr. Martinez"),
        Hospital("Infectious Disease Hospital", "888  Ave.", "infectious diseases", "Dr. Adams"),
        Hospital("Kidney Health Center", "222  birta hospital.", "nephrology", "Dr. Lee"),
        Hospital("Arthritis Clinic", "333  St.", "rheumatology", "Dr. Davis"),
        Hospital("Alzheimer's Care Facility", "444  Ln.", "neurology", "Dr. Harris")
    };

    string recommendedHospital;
    string location;
    string doctorName;

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
        cout << "Recommended Hospital: " << recommendedHospital << "\n"
             << "Location: " << location << "\n"
             << "Doctor: " << doctorName << endl;
    } else {
        cout << "No suitable hospital found for the disease." << endl;
    }
}

int main() {
    // User input for patient details
    string patientName;
    int patientAge;
    string patientMobile;
    string patientCity;
    string patientDisease;

    cout << "Enter Patient Name: ";
    getline(cin, patientName);
    cout << "Enter Patient Age: ";
    cin >> patientAge;
    cin.ignore(); // Clear the newline from the input buffer
    cout << "Enter Patient Mobile No: ";
    getline(cin, patientMobile);
    cout << "Enter Patient City: ";
    getline(cin, patientCity);
    cout << "Enter Patient Disease (e.g., Lung Cancer, Blood Cancer, Skin Disease, Corona, Diabetes, Heart Disease, HIV/AIDS, Tuberculosis, Asthma, Chronic Kidney Disease, Arthritis, Alzheimer's Disease): ";
    getline(cin, patientDisease);

    Patient newPatient(patientName, patientAge, patientMobile, patientCity, patientDisease);
    
    // Display patient information
    newPatient.displayInfo();
    
    // Recommend a hospital and doctor
    recommendHospital(newPatient);

    return 0;
}
