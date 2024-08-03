import React, { useState } from 'react';
import PatientForm from './components/PatientForm';
import DietPlanDisplay from './components/DietPlanDisplay';
import FeedbackForm from './components/FeedbackForm';
import 'bootstrap/dist/css/bootstrap.min.css';

const App = () => {
  const [dietPlan, setDietPlan] = useState('');
  const [userId, setUserId] = useState('');
  const [feedback, setFeedback] = useState(null);

  const handlePatientSubmit = (dietPlanData, userIdData) => {
    setDietPlan(dietPlanData);
    setUserId(userIdData);
    setFeedback(null);
  };

  const handleFeedbackSubmit = async (feedbackScore) => {
    try {
      const body = JSON.stringify({ userId, feedback_score: feedbackScore });

      const response = await fetch('http://0.0.0.0:4700/feedback', {
        method: 'POST',
        headers: {
          'Content-Type': 'text/plain'
        },
        body: body
      });

      if (response.ok) {
        setFeedback(feedbackScore);
      } else {
        console.error('Error submitting feedback:', response.statusText);
      }
    } catch (error) {
      console.error('Network error:', error);
    }
  };

  return (
    <div className="container mt-5">
      <h1 className="text-center mb-4">Nutrition System</h1>
      <PatientForm onSubmit={handlePatientSubmit} />
      {dietPlan && <DietPlanDisplay dietPlan={dietPlan} />}
      {dietPlan && userId && <FeedbackForm userId={userId} onSubmit={handleFeedbackSubmit} />}
    </div>
  );
};

export default App;
