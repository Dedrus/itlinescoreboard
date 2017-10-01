namespace BeOpen.Devices.ItLineScoreboards.NetworkCommunication.Data
{
    public class StringMessage
    {
        public readonly byte StringIndex;
        public readonly StringProfile StringProfile;
        public readonly string Value;

        public StringMessage(byte stringIndex, StringProfile stringProfile, string value)
        {
            Value = value;
            StringProfile = stringProfile;
            StringIndex = stringIndex;
        }
    }
}