import React, { useState } from 'react';

const FeedbackForm = ({ userId, onSubmit }) => {
  const [feedbackScore, setScore] = useState('');
  const [submissionStatus, setSubmissionStatus] = useState(null);

  const handleSubmit = async (event) => {
    event.preventDefault();
    if (feedbackScore && userId) {
      const feedbackData = {
        userId,
        feedback_score: parseInt(feedbackScore)
      };
      const body = JSON.stringify(feedbackData);
      console.log('Submitting feedback:', body);

      try {
        const response = await fetch('http://0.0.0.0:4700/feedback', {
          method: 'POST',
          headers: {
            'Content-Type': 'text/plain'
          },
          body: body
        });

        if (response.ok) {
          console.log('Feedback submitted successfully');
          setSubmissionStatus('success');
          onSubmit(parseInt(feedbackScore));
        } else {
          console.error('Error submitting feedback:', response.statusText);
          setSubmissionStatus('error');
        }
      } catch (error) {
        console.error('Network error:', error);
        setSubmissionStatus('error');
      }
    } else {
      console.error('Feedback score or userId is missing');
      setSubmissionStatus('error');
    }
  };

  return (
    <div>
      <form onSubmit={handleSubmit}>
        <div className="form-group">
          <label>Feedback Score (1-10):
            <input type="number" className="form-control" value={feedbackScore} onChange={(e) => setScore(e.target.value)} min="1" max="10" required />
          </label>
        </div>
        <button type="submit" className="btn btn-primary">Submit Feedback</button>
      </form>
      {submissionStatus === 'success' && <div className="alert alert-success mt-3">Feedback submitted successfully!</div>}
      {submissionStatus === 'error' && <div className="alert alert-danger mt-3">There was an error submitting your feedback. Please try again.</div>}
    </div>
  );
};

export default FeedbackForm;
