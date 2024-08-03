import React, { useState } from 'react';

const PatientForm = ({ onSubmit }) => {
  const [name, setName] = useState('');
  const [age, setAge] = useState('');
  const [gender, setGender] = useState('');
  const [height, setHeight] = useState('');
  const [weight, setWeight] = useState('');
  const [diseases, setDiseases] = useState('');
  const [userId, setUserId] = useState('');

  const handleSubmit = async (event) => {
    event.preventDefault();

    const patientData = {
      name,
      age: parseInt(age),
      gender,
      height: parseFloat(height),
      weight: parseFloat(weight),
      diseases: diseases.split(',').map(disease => disease.trim())
    };

    const body = JSON.stringify(patientData);

    try {
      const response = await fetch('http://0.0.0.0:4700/', {
        method: 'POST',
        headers: {
          'Content-Type': 'text/plain'
        },
        body: body
      });

      if (response.ok) {
        const data = await response.json();
        setUserId(data.userId);
        onSubmit(data.diet_plan, data.userId, data.name); // Pass user name to parent component
      } else {
        console.error('Error submitting patient data:', response.statusText);
      }
    } catch (error) {
      console.error('Network error:', error);
    }
  };

  return (
    <form onSubmit={handleSubmit} className="mb-4">
      <div className="mb-3">
        <label htmlFor="name" className="form-label">Name:</label>
        <input type="text" className="form-control" id="name" value={name} onChange={(e) => setName(e.target.value)} required />
      </div>
      <div className="mb-3">
        <label htmlFor="age" className="form-label">Age:</label>
        <input type="number" className="form-control" id="age" value={age} onChange={(e) => setAge(e.target.value)} required />
      </div>
      <div className="mb-3">
        <label htmlFor="gender" className="form-label">Gender:</label>
        <input type="text" className="form-control" id="gender" value={gender} onChange={(e) => setGender(e.target.value)} required />
      </div>
      <div className="mb-3">
        <label htmlFor="height" className="form-label">Height (cm):</label>
        <input type="number" className="form-control" id="height" value={height} onChange={(e) => setHeight(e.target.value)} required />
      </div>
      <div className="mb-3">
        <label htmlFor="weight" className="form-label">Weight (kg):</label>
        <input type="number" className="form-control" id="weight" value={weight} onChange={(e) => setWeight(e.target.value)} required />
      </div>
      <div className="mb-3">
        <label htmlFor="diseases" className="form-label">Diseases (comma-separated):</label>
        <input type="text" className="form-control" id="diseases" value={diseases} onChange={(e) => setDiseases(e.target.value)} />
      </div>
      <button type="submit" className="btn btn-primary">Submit</button>
    </form>
  );
};

export default PatientForm;
