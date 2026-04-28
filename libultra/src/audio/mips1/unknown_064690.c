#include <libaudio.h>

/**
 * Move a synthesizer voice to a different auxiliary bus channel.
 */
void audio_set_channel_priority(ALCSPlayer *seqp, u8 chan) {
    ALEvent evt;

    evt.type = AL_SEQP_MIDI_EVT;
    evt.msg.midi.ticks  = 0;
    evt.msg.midi.status = AL_MIDI_ControlChange;
    evt.msg.midi.byte1  = AL_MIDI_UNK_5F;
    evt.msg.midi.byte2  = chan;
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
